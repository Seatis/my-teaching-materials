# The Reverser of the Sith
- Create a `POST /sith` endpoint
- That receives a simple json object:
```json
{
  "text": "This is my example sentence. Just for fun."
}
```
- And responds with a simplified yoda speak simply switching every 2 words:
```json
{
  "sith_text": "Is this example my sentence. Arrgh. Uhmm. For just fun. Err..err.err."
}
```
- it keeps the capital positions and the end of sentences
- if a sentence doesnt contain even number of words, it leaves the last as is
- always puts (one or two) random things at the end of sentences
- if the input doesnt contain the text or its empty, respond with:
```json
{
  "error": "Feed me some text you have to, padawan young you are. Hmmm."
}
```
