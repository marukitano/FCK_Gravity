# Gravity

Gravity is a gravity-driven vector watchface for the Pebble Time 2.

---

## Deutsch

**Gravity** ist eine modernisierte Version des Pebble-Ziffernblatts
**Upright**, das ursprünglich von **Jnm** entwickelt wurde.

Die Uhrzeit wird mit vier Ziffernblöcken dargestellt. Der
Beschleunigungssensor erkennt die Ausrichtung der Uhr und dreht die gesamte
Anzeige entsprechend der Schwerkraft, sodass die Uhrzeit beim Bewegen des
Handgelenks aufrecht bleibt.

### Funktionen

- Entwickelt für die Pebble Time 2 (`emery`, 200 × 228 Pixel)
- Vektorbasiert gezeichnete Ziffern
- Gemeinsame Rotation aller vier Ziffernblöcke
- Unterstützung für das 12- und 24-Stunden-Format
- Feste virtuelle Kegelbahn für eine stabile Bewegung
- Kein Zittern bei annähernd waagerechter Haltung
- Gleichmäßige Winkeldeadzone
- Gedämpfte Federbewegung mit leichtem natürlichem Übersteuern
- Sensorabtastung mit 10 Hz
- Darstellung mit ungefähr 18 Bildern pro Sekunde

### Bewegungsmodell

Die Anzeige bewegt sich auf einer festen virtuellen Kreisbahn. Dieses Modell
entspricht einem umgekippten Kegel, dessen Grundfläche sich um den Mittelpunkt
drehen kann, den Mittelpunkt selbst aber niemals überquert.

Dadurch bleibt die Ausrichtung auch dann stabil, wenn die Uhr nahezu waagerecht
gehalten wird. Kleine unbeabsichtigte Bewegungen werden von einer
Winkeldeadzone ignoriert. Eine gedämpfte Federbewegung sorgt beim Abbremsen für
ein dezentes und flüssiges Übersteuern.

### Ursprung

Gravity basiert auf dem ursprünglichen Pebble-Watchface **Upright** von
**Jnm**. Die ursprünglichen Zifferngrafiken wurden in Vektorpfade umgewandelt
und das Watchface für die Pebble Time 2 sowie das aktuelle Pebble-SDK
modernisiert.

### Lizenz

Neue Gravity-Quelltexte und Änderungen von Maru werden unter der
[MIT-Lizenz](LICENSE) veröffentlicht.

Der ursprüngliche Upright-Quellcode und die ursprünglichen Grafiken bleiben
von der BSD-Lizenzfreigabe des ursprünglichen Entwicklers abgedeckt.

Weitere Informationen befinden sich in
[THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md).

---

## English

**Gravity** is a modernized version of the Pebble watchface **Upright**,
originally created by **Jnm**.

The time is displayed using four separate digit blocks. The accelerometer
detects the orientation of the watch and rotates the entire display according
to gravity, keeping the time upright as the wrist moves.

### Features

- Designed for the Pebble Time 2 (`emery`, 200 × 228 pixels)
- Vector-rendered digits
- Unified rotation of all four digit blocks
- Support for both 12-hour and 24-hour time formats
- Fixed virtual cone orbit for stable movement
- No jitter when the watch is held nearly flat
- Consistent angular deadzone
- Damped spring motion with subtle natural overshoot
- 10 Hz accelerometer sampling
- Rendering at approximately 18 frames per second

### Motion model

The display moves along a fixed virtual circular orbit. This model behaves like
an overturned cone whose base can rotate around the center but can never pass
through it.

This keeps the orientation stable even when the watch is held nearly flat.
Small unintended movements are ignored by an angular deadzone. A damped spring
adds a subtle and fluid overshoot as the display comes to rest.

### Origin

Gravity is based on the original Pebble watchface **Upright** by **Jnm**. The
original digit graphics were converted into vector paths, and the watchface
was modernized for the Pebble Time 2 and the current Pebble SDK.

### License

New Gravity source code and modifications by Maru are released under the
[MIT License](LICENSE).

The original Upright source code and graphics remain subject to the BSD
license grant made by the original developer.

See [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md) for details.
