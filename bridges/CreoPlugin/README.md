# IPX Quote Creo Plugin

This is the Creo-in-process Toolkit plugin used to validate the Creo extraction path before wiring the data back into the WPF pricing flow.

## First test flow

1. Build `CreoPlugin.vcxproj` for `Release|x64`.
2. For manual local testing, copy `protk.dat.template` to a local `protk.dat` and replace `{{PLUGIN_DLL}}` / `{{TEXT_DIR}}` with paths on the current machine.
3. Start Creo and open a `.prt`, `.asm`, or `.drw` file.
4. Run `IPX Quote -> Export Current Metrics`.
5. Check `%TEMP%\IPXQuoteCreoPlugin\last-result.json`, or set `IPX_QUOTE_CREO_METRICS` to override the output path.
