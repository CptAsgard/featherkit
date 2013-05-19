#pragma once
#include <queue>
#include <framework/input/event.h>
#include <framework/internal/vec2.h>

namespace windbreeze
{
    class InputBackend;

    class InputHandler
    {
        public:
            InputHandler(InputBackend& backend) : inputBackend(backend){}
            void processEvents(bool keepLast = false);
            bool pollEvent(Event& event);
            const std::queue<Event>& getEventQueue() const;

            bool isKeyPressed(Keyboard::Code code) const;

            bool isMouseButtonPressed(Mouse::Button b) const;
            IntVec2 getMouseGlobalPosition() const;
            IntVec2 getMouseWindowPosition() const;
            void setMouseGlobalPosition(int32_t x, int32_t y);
            void setMouseWindowPosition(int32_t x, int32_t y);

            bool isGamepadConnected(uint32_t id) const;
            uint32_t getGamepadButtonCount(uint32_t id) const;
            bool isGamepadButtonPressed(uint32_t id, uint32_t button) const;
            bool gamepadHasAxis(uint32_t id, Gamepad::Axis axis) const;
            float getGamepadAxisPosition(uint32_t id, Gamepad::Axis axis) const;

            void setGamepadThreshold(float threshold);
            void setKeyRepeatEnabled(bool enabled);
        private:
            InputBackend& inputBackend;
            std::queue<Event> eventQueue;
    };

/** @addtogroup UserInterface
 *@{
 *  @class InputHandler
 *@}
 *
 *  @class InputHandler
 *  @brief Provides an access to input events and settings, as well as the current state of the input devices. Must be given an InputBackend upon creaton which is stored internally as a reference. 
 * 
 * 
 *  @fn InputHandler::InputHandler(InputBackend& backend) 
 *  @brief Construct an InputHandler with the given backend.
 *  
 *  @param backend InputBackend given.
 *
 *  @fn void InputHandler::processEvents(bool keepLast = false)
 *  @brief Fetch events generated by the backend. This clears the event queue in the backend and stores the events for polling. Must be called before using InputHandler::pollEvent, otherwise there will be no events to poll.
 *
 *  @param keepLast If this is false, the InputHandler will discard all unhandled events. Otherwise, new events will be queued after the old ones. Default value is false.
 *
 *  @fn bool InputHandler::pollEvent(Event& event)
 *  @brief Access the frontmost event in the event queue, removing it in the process.
 *
 *  @param event Event instance in which to store the frontmost event.
 *  @return True if an event was given, or false if the event queue was empty.
 *
 *  @fn const std::queue<Event>& InputHandler::getEventQueue() const
 *  @brief Access the event queue.
 *
 *  @return Const reference to the internal event queue.
 *
 *  @fn bool InputHandler::isKeyPressed(Keyboard::Code code) const
 *  @brief Check if a key on the keyboard is pressed or not.
 *
 *  @param code The key to check.
 *  @return True if the key is currently pushed down.
 *
 *  @fn bool InputHandler::isMouseButtonPressed(Mouse::Button b) const
 *  @brief Check if a button on the mouse is pressed or not.
 *
 *  @param b The button to check.
 *  @return True if the button is currently pushed down.
 *
 *  @fn IntVec2 InputHandler::getMouseGlobalPosition() const
 *  @brief Access the current mouse position relative to the whole screen.
 *
 *  @return Coordinates as a vector.
 *
 *  @fn IntVec2 InputHandler::getMouseWindowPosition() const
 *  @brief Access the current mouse position relative to the window.
 *
 *  @return Coordinates as a vector.
 *
 *  @fn void InputHandler::setMouseGlobalPosition(int32_t x, int32_t y)
 *  @brief Set the mouse position relative to the whole screen.
 *
 *  @param x X coordinate.
 *  @param y Y coordinate.
 *
 *  @fn void InputHandler::setMouseWindowPosition(int32_t x, int32_t y)
 *  @brief Set the mouse position relative to the window.
 *
 *  @param x X coordinate.
 *  @param y Y coordinate.
 *
 *  @fn bool InputHandler::isGamepadConnected(uint32_t id) const
 *  @brief Check if a gamepad is connected.
 *  
 *  @param id Gamepad to check.
 *  @return True if connected.
 *
 *  @fn uint32_t InputHandler::getGamepadButtonCount(uint32_t id) const
 *  @brief Get the amount of buttons available on a specific gamepad.
 *
 *  @param id Gamepad to check.
 *  @return Amount of buttons.
 *
 *  @fn bool InputHandler::isGamepadButtonPressed(uint32_t id, uint32_t button) const
 *  @brief Check if a button on a specific gamepad is being pressed down.
 *
 *  @param id Gamepad to check.
 *  @param button Button to check.
 *  @return True if the button is pressed.
 *
 *  @fn bool InputHandler::gamepadHasAxis(uint32_t id, Gamepad::Axis axis) const
 *  @brief Check if a gamepad has a specific axis.
 *
 *  @param id Gamepad to check.
 *  @param axis Axis to look for.
 *  @return True if the axis exists.
 *
 *  @fn float InputHandler::getGamepadAxisPosition(uint32_t id, Gamepad::Axis axis) const
 *  @brief Access the current position for an axis on a specific gamepad.
 *
 *  @param id Gamepad to check.
 *  @param axis Axis of which to get the position.
 *  @return Position of the axis.
 *
 *  @fn void InputHandler::setGamepadThreshold(float threshold)
 *  @brief Set the threshold level for when Event::GAMEPADMOVED events are fired.
 *
 *  @param threshold Threshold level.
 *
 *  @fn void InputHandler::setKeyRepeatEnabled(bool enabled)
 *  @brief Set Event::KEYPRESSED events to only fire once instead of continuously if a key is being pressed down.
 *
 *  @param enabled True for on, false for off.
 */
}
