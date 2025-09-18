#pragma once

#ifdef USE_ESP32

#include "esphome/core/component.h"
#include "esphome/components/button/button.h"
#include "ble_mi_remote.h"
#include <string>

namespace esphome {
	namespace ble_mi_remote {
		class BleMiRemoteButton : public button::Button, public Component {
			public:
				void set_parent(BleMiRemote *parent) { parent_ = parent; }

				void set_value(int8_t value) { value_ = value; }

				void set_pair_keys(uint8_t first_key, uint8_t second_key) {
					pair_key_a_ = first_key;
					pair_key_b_ = second_key;
					is_pair_button_ = true;
				}

				void set_pair_duration(uint32_t duration_ms) { pair_duration_ms_ = duration_ms; }

			protected:
				void press_action() override;

				int8_t value_{-1};
				bool is_pair_button_{false};
				uint8_t pair_key_a_{0};
				uint8_t pair_key_b_{0};
				uint32_t pair_duration_ms_{10000};

				BleMiRemote *parent_;
		};
	}  // namespace ble_mi_remote
}  // namespace esphome

#endif
