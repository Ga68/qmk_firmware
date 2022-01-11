# ###############
# ### Enabled ###
# ###############

AUTO_SHIFT_ENABLE   = yes
COMBO_ENABLE        = yes
ENCODER_ENABLE      = yes
EXTRAKEY_ENABLE     = yes # Audio control and System control
MOUSEKEY_ENABLE     = yes # Controlling mouse movement and clicks
OLED_ENABLE         = yes
  OLED_DRIVER = SSD1306


# ################
# ### Disabled ###
# ################

KEY_OVERRIDE_ENABLE = no
TAP_DANCE_ENABLE    = no
COMMAND_ENABLE      = no # To avoid problems with Space Cadet (LSPO, RSPO, etc.)
SPACE_CADET_ENABLE  = no


# ####################
# ### Space Saving ###
# ####################

EXTRAFLAGS += -flto

BOOTMAGIC_ENABLE   = no
CONSOLE_ENABLE     = no
GRAVE_ESC_ENABLE   = no
MAGIC_ENABLE       = no
RGBLIGHT_ENABLE    = no
SWAP_HANDS_ENABLE  = no
UNICODE_ENABLE     = no
