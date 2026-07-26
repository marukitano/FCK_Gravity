# FCK_Gravity

## Deutsch

**Gravity** ist eine modernisierte Version des Pebble-Ziffernblatts **Upright**, das ursprünglich von Jnm entwickelt wurde.

Ziel dieses Projekts ist es, das ursprüngliche Ziffernblatt an die **Pebble Time 2**, deren größeres Farbdisplay und das aktuelle Pebble-SDK anzupassen.

### Funktionsweise

Die Uhrzeit wird mit vier getrennten Ziffernblöcken dargestellt.

Der Beschleunigungssensor der Uhr erkennt ihre Ausrichtung. Die gesamte Anzeige dreht sich entsprechend der Schwerkraft, sodass die Uhrzeit bei Bewegungen des Handgelenks aufrecht bleibt.

### Geplante Funktionen

- Unterstützung für die Pebble Time 2
- Kompatibilität mit dem aktuellen Pebble-SDK
- Anpassung des Layouts an das größere Display der Pebble Time 2
- Frei einstellbare Farben
- Verbesserte Akkulaufzeit
- Unterstützung für das 12- und 24-Stunden-Format

### Libelle

Durch Schütteln des Handgelenks wird vorübergehend eine kreisförmige Libelle eingeblendet.

Innerhalb des großen Kreises befindet sich ein kleinerer Kreis, der sich abhängig von der Neigung der Uhr bewegt.

Einen konkreten praktischen Zweck hat diese Funktion bisher nicht — sie ist enthalten, weil sie cool aussieht.

### Projektstatus

Gravity befindet sich derzeit in Entwicklung.

Der bestehende Quellcode ist noch für die ursprüngliche monochrome Pebble-Plattform geschrieben und verwendet Schnittstellen, die mit dem aktuellen Pebble-SDK nicht mehr kompatibel sind.

Der erste Entwicklungsschritt besteht darin, die Kompatibilität mit dem aktuellen SDK wiederherzustellen und dabei das ursprüngliche Verhalten der schwerkraftabhängigen Anzeige beizubehalten.

### Lizenz

Neue Gravity-Quelltexte und Änderungen von Maru werden unter der [MIT-Lizenz](LICENSE) veröffentlicht.

Gravity basiert auf **Upright** von **Jnm**. Der ursprüngliche Quellcode und die ursprünglichen Grafiken bleiben von der BSD-Lizenzfreigabe des ursprünglichen Entwicklers abgedeckt.

Weitere Informationen befinden sich in [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md).

---

## English

**Gravity** is a modernization of the Pebble watchface **Upright**, originally created by Jnm.

The goal of this project is to adapt the original watchface to the **Pebble Time 2**, its larger color display and the current Pebble SDK.

### How it works

The time is displayed using four separate number blocks.

The watch's accelerometer detects its orientation and rotates the entire display according to gravity, keeping the time upright as the wrist moves.

### Planned features

- Support for the Pebble Time 2
- Compatibility with the current Pebble SDK
- A layout adapted to the larger Pebble Time 2 display
- Freely configurable colors
- Improved battery efficiency
- Support for both 12-hour and 24-hour time formats

### Spirit level

Shaking the wrist will temporarily open a circular spirit level.

A smaller circle inside it will move according to the current tilt of the watch.

There is no specific practical purpose planned for this feature yet — it is included because it looks cool.

### Project status

Gravity is currently under development.

The existing source code still targets the original monochrome Pebble platform and uses APIs that are no longer compatible with the current Pebble SDK.

The first development step is to restore compatibility with the current SDK while preserving the original gravity-based behavior.

### License

New Gravity code and modifications by Maru are released under the [MIT License](LICENSE).

Gravity is based on **Upright** by **Jnm**. The original source code and assets remain subject to the BSD license grant made by the original developer.

See [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md) for details.
