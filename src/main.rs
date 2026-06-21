mod engine;
fn main() {
    let config = engine::app::EngineConfig::default();
    let mut game = engine::app::Engine::new(config);
    let _ = game.run();
    println!("Hello, world!");
}
