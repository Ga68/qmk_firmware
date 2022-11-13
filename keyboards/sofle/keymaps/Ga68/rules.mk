# ############
# ### Used ###
# ############

SRC += leader.c
SRC += leader_sequences.c


CAPS_WORD_ENABLE    = yes
  SRC += caps_word.c
AUTO_SHIFT_ENABLE   = yes
  SRC += autoshift.c
COMBO_ENABLE        = yes
  SRC += combos.c
MOUSEKEY_ENABLE     = yes # Controlling mouse movement and clicks
OLED_ENABLE         = yes
  OLED_DRIVER = SSD1306
  SRC += oled.c
EXTRAKEY_ENABLE     = yes # Audio control and System control

# ##############
# ### Unused ###
# ##############

ENCODER_ENABLE      = no
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
