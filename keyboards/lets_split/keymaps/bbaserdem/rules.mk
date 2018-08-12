# Build options

BACKLIGHT_ENABLE = no		# Switch LEDs
MOUSEKEY_ENABLE = yes		# Emulates mouse key using keypresses
RGBLIGHT_ENABLE = yes 		# LED strips
TAP_DANCE_ENABLE = no 		# Use multi-tap features
AUDIO_ENABLE = no 			# Audio stuff

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
