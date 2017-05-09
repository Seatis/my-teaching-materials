# The Hungarian CamelIzer Service
- Create a `POST /translate` endpoint
- That receives a simple json object:
```json
{
  "text": "Ez egy példamondat. Remélem célbatalál.",
  "lang": "hu"
}
```
- And responds with the translated text and its language:
```json
{
  "translated": "Evez evegy pévéldavamovondavat. Revemévélevem cévélbavavtavalávál.",
  "lang": "teve"
}
```
- from hungarian translate to teve language
- from english translate to any form of gibberish:
  - https://www.wikiwand.com/en/Gibberish_(language_game)
- if the input doesnt contain the text (and the language) or its empty, respond with:
```json
{
  "error": "I can't translate that!"
}
```
