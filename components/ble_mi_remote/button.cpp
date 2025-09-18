
#ifdef USE_ESP32

#include "button.h"
#include "esphome/core/log.h"
#include <string>

namespace esphome {
	namespace ble_mi_remote {
		static const char *const TAG = "ble_mi_remote";

		void BleMiRemoteButton::press_action() {
			if (is_pair_button_) {
				// Press both special keys without timer to keep them held
				parent_->pressSpecial((uint8_t) pair_key_a_, /*with_timer=*/false);
				parent_->pressSpecial((uint8_t) pair_key_b_, /*with_timer=*/false);
				// Schedule release after the pairing duration
				this->set_timeout("pair_release", pair_duration_ms_, [this]() {
					this->parent_->release();
				});
				return;
			}
			if (value_ > -1) {
				parent_->pressSpecial((uint8_t) value_);
			} else {
				parent_->release();
			}
		}
	}  // namespace ble_mi_remote
}  // namespace esphome

#endif
