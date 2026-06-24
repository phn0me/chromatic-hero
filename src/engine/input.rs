use winit::event::ElementState;
#[allow(dead_code)]
pub struct InputState {
    pub keys_down: [bool; 256],
    pub keys_just_pressed: [bool; 256],
}

#[allow(dead_code)]
impl InputState {
    pub fn update(&mut self, key_code: winit::keyboard::KeyCode, state: ElementState) {
        let idx = key_code as usize;
        if idx >= 256 {
            return;
        } // Safety clamp

        match state {
            ElementState::Pressed => {
                self.keys_down[idx] = true;
                self.keys_just_pressed[idx] = true;
            }
            ElementState::Released => {
                self.keys_down[idx] = false;
            }
        }
    }

    pub fn reset_just_pressed(&mut self) {
        self.keys_just_pressed.fill(false);
    }
}
