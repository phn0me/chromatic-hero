use winit::{
    application::ApplicationHandler,
    dpi::LogicalSize,
    event::{ElementState, KeyEvent, WindowEvent},
    event_loop::{self, ActiveEventLoop, ControlFlow::Poll, EventLoop},
    window::{Window, WindowId},
};

pub struct Engine {
    pub window: Option<Window>,
    pub config: EngineConfig,
}

pub struct EngineConfig {
    title: String,
    width: u32,
    height: u32,
    resizable: bool,
    decorations: bool,
}

impl Default for EngineConfig {
    fn default() -> Self {
        Self::new("Chromatic Hero".to_string(), 800, 600, false, true)
    }
}

impl EngineConfig {
    pub fn new(title: String, width: u32, height: u32, resizable: bool, decorations: bool) -> Self {
        EngineConfig {
            title,
            width,
            height,
            resizable,
            decorations,
        }
    }
}
impl Engine {
    pub fn new(config: EngineConfig) -> Self {
        Self {
            window: None,
            config,
        }
    }
    pub fn run(&mut self) -> Result<(), Box<dyn std::error::Error>> {
        let event_loop = EventLoop::new()?;
        event_loop.set_control_flow(Poll);
        event_loop.run_app(self)?;
        Ok(())
    }
}

impl ApplicationHandler for Engine {
    fn resumed(&mut self, event_loop: &event_loop::ActiveEventLoop) {
        if self.window.is_none() {
            let attributes = Window::default_attributes()
                .with_title(&self.config.title)
                .with_inner_size(LogicalSize::new(
                    self.config.width as f64,
                    self.config.height as f64,
                ))
                .with_resizable(self.config.resizable)
                .with_decorations(self.config.decorations);

            self.window = Some(
                event_loop
                    .create_window(attributes)
                    .expect("Failed to create window"),
            );

            // Kickstart the render loop
            if let Some(win) = &self.window {
                win.request_redraw();
            }
        }
    }
    fn window_event(
        &mut self,
        event_loop: &ActiveEventLoop,
        _window_id: WindowId,
        event: WindowEvent,
    ) {
        match event {
            WindowEvent::CloseRequested => {
                println!("Close requested!");
                // In a real app, maybe save state here
                // For now, exit
                event_loop.exit(); // winit exits automatically on close on most platforms, but explicit is fine
            }
            WindowEvent::RedrawRequested => {
                if let Some(window) = &self.window {
                    // TODO: Draw pixels here soon
                    window.request_redraw();
                    // println!("Resized: {:?}", window.inner_size());
                }
            }
            WindowEvent::KeyboardInput {
                event:
                    KeyEvent {
                        logical_key: _key,
                        state: ElementState::Pressed,
                        ..
                    },
                ..
            } => {}
            _ => {}
        }
    }
}
