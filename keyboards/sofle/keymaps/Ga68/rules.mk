# ############
# ### Used ###
# ############

SRC += caps_word.c
SRC += leader.c


AUTO_SHIFT_ENABLE   = yes
  SRC += autoshift.c
COMBO_ENABLE        = yes
  SRC += combos.c
MOUSEKEY_ENABLE     = yes # Controlling mouse movement and clicks
OLED_ENABLE         = yes
  OLED_DRIVER = SSD1306
  SRC += oled.c

ENCODER_ENABLE      = no
EXTRAKEY_ENABLE     = no # Audio control and System control

# ##############
# ### Unused ###
# ##############

KEY_OVERRIDE_ENABLE = no
#   SRC += overrides.c
TAP_DANCE_ENABLE    = no
LEADER_ENABLE       = no
# if you want LEADER key, be sure to comment
#   #define DISABLE_LEADER
# in config.h


# ####################
# ### Space Saving ###
# ####################

EXTRAFLAGS += -flto
LTO_ENABLE  = yes

CONSOLE_ENABLE     = no
COMMAND_ENABLE     = no # To avoid problems with Space Cadet (LSPO, RSPO, etc.)
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE   = no
MAGIC_ENABLE       = no

BOOTMAGIC_ENABLE   = no
RGBLIGHT_ENABLE    = no
SWAP_HANDS_ENABLE  = no
UNICODE_ENABLE     = no
