# Log extension
- Extend your `/log` endpoint with optional query parameters:
  - `count=10`, then the result should contain only the latest 10 entries
  - `page=2`, then the result should contain the second 10 of latest entries
- If you still on fire and have time:
  - `q=search`, then the result should contain only those entries that have the `q` term (in this case "search") in the data field
