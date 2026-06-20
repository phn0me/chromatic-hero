use winit::{
    dpi,
    window::{Window, WindowAttributes},
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
}
