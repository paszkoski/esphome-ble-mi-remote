#ifdef USE_ESP32

#include "button.h"
#include "esphome/core/log.h"
#include <string>

namespace esphome {
	namespace ble_mi_remote {
		static const char *const TAG = "ble_mi_remote";

		void BleMiRemoteButton::press_action() {
			if (value_ > -1) {
				parent_->pressSpecial((uint8_t) value_);
			} else if (value_ == -2) {
				// Special value for pairing button
				parent_->startPairing();
			} else {
				parent_->release();
			}
		}
	}  // namespace ble_mi_remote
}  // namespace esphome

#endif
