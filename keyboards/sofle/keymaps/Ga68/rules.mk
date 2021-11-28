# ###############
# ### Enabled ###
# ###############
COMBO_ENABLE 				= yes
ENCODER_ENABLE 			= yes
EXTRAKEY_ENABLE 		= yes # Audio control and System control
KEY_OVERRIDE_ENABLE = yes
MOUSEKEY_ENABLE 		= yes # Controlling mouse movement and clicks
OLED_ENABLE 				= yes
	OLED_DRIVER = SSD1306

# ################
# ### Disabled ###
# ################
AUTO_SHIFT_ENABLE = no
TAP_DANCE_ENABLE  = no

# ####################
# ### Space Saving ###
# ####################
EXTRAFLAGS += -flto

BOOTMAGIC_ENABLE   = no
CONSOLE_ENABLE     = no
COMMAND_ENABLE     = no
GRAVE_ESC_ENABLE   = no
MAGIC_ENABLE       = no
RGBLIGHT_ENABLE 	 = no
SPACE_CADET_ENABLE = no
SWAP_HANDS_ENABLE  = no
UNICODE_ENABLE     = no
