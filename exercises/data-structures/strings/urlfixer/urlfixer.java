public class UrlFixer {
  public static void main(String... args){
    StringBuilder sb = new StringBuilder("https//www.reddit.com/r/nevertellmethebots");

    // Accidentally I got the wrong URL for a funny subreddit. It's probably "odds" and not "bots"
    // Also, the URL is missing a crutial component, find out what it is and insert it too!

    System.out.println(sb.toString());
  }
}
