import java.util.Arrays;
import java.util.List;

public class Workshop03 {
    public static void main(String... args) throws IOException {
        List<HtmlTag> tags = Arrays.asList(
                new HtmlTag("a", Arrays.asList("href", "target")),
                new HtmlTag("img", Arrays.asList("src", "alt")));

        // Import the Gson library
        // Serialize "tags" to JSON using the Gson library
        // The filename should be: "tags.json"
    }
}

class HtmlTag {
    private String name;
    private List<String> attributes;

    public HtmlTag(String name, List<String> attrs) {
        this.name = name;
        this.attributes = attrs;
    }

    public String getName(){
        return name;
    }

    public List<String> getAttributes(){
        return attributes;
    }
}
