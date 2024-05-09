#ifndef TIC_TAC_TOE_SOUNDS_CONTROLLER_H
#define TIC_TAC_TOE_SOUNDS_CONTROLLER_H

class SoundsController {
private:
    void playSound(std::string soundPath);
public:
    void playClickSound();
    void playGameOverSound();
};

#endif