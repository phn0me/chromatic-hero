use winit::{dpi, window::{Window, WindowAttributes}};

pub struct Engine {
    pub window: Option<Window>,
    pub config: EngineConfig,
}

struct EngineConfig {
    title: String,
    width: u32,
    height: u32,
    resizable: bool,
    decorations: bool,
    full_screen: bool,
}

impl Default for EngineConfig {
    fn default() -> Self {
        Self::new("Chromatic Hero".to_string(), 800, 600, false, true, false)
    }
}

impl EngineConfig {
    pub fn new(title: String, width: u32, height: u32, resizable: bool, decorations: bool, full_screen: bool) -> Self {
        EngineConfig { title, width, height, resizable, decorations, full_screen }
    }
}
impl Engine {
    pub fn new(title: String, width: u32, height: u32) -> Self {
        let attributes: WindowAttributes = WindowAttributes::default().with_title(title).with_inner_size(dpi::LogicalSize::new(width, height));

    }
}
