
# Day 4: Finalize frontend with live data

## Stories

### Add full CRUD functionality:
- Playlist can be deleted
- Tracks can be deleted from playlists
- Playlist can be created from the frontend
- Tracks can be added from to a playlist

### Close the gaps
- Check the frontend again
- Re-read the specification
- Check the frontend again
- Ask somebody from *another table* to test your app
- Check the frontend again

## Optional

### Load track artwork from Last.fm
- Your API key is: `ee125f318852fc7d1c2f4e21458a0035`
- Use the `artist.getInfo` API method: http://www.last.fm/api/show/artist.getInfo
- On each track loading, request the band photo (large, square one)
- If the same artist is playing again, don't fetch a new API call
	- http://www.last.fm/api/tos
	- "You will implement suitable caching in accordance with the HTTP headers sent with web service responses. You will not make more than 5 requests per originating IP address per second, averaged over a 5 minute period, without prior written consent. You agree to cache similar artist and any chart data (top tracks, top artists, top albums) for a minimum of one week."
