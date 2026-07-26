# Gravity

**Gravity** is a modernization of the Pebble watchface **Upright**, originally created by Jnm.

The goal of this project is to adapt the original watchface to the **Pebble Time 2**, its larger color display and the current Pebble SDK.

## How it works

The time is displayed using four separate number blocks.

The watch's accelerometer detects its orientation and rotates the display according to gravity, keeping the time upright as the wrist moves.

## Planned features

- Support for the Pebble Time 2
- Compatibility with the current Pebble SDK
- A layout adapted to the Pebble Time 2 display
- Freely configurable colors
- Improved battery efficiency
- Support for both 12-hour and 24-hour time formats

## Spirit level

Shaking the wrist will temporarily open a circular spirit level.

A smaller circle inside it will move according to the current tilt of the watch.

There is no specific practical purpose planned for this feature yet — it is included because it looks cool.

## Project status

Gravity is currently under development.

The existing source code still targets the original monochrome Pebble platform and uses APIs that are no longer compatible with the current Pebble SDK.

The first development step is to restore SDK compatibility while preserving the original gravity-based behavior.

## Credits

Based on the original **Upright** watchface by Jnm.

The original developer granted permission to copy, modify and improve the project under BSD license terms.
