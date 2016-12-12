package lombok.foods;

/**
 * Created by kicsen on 2016. 12. 12..
 */
public class Cheese extends AbstractFood {
    public Cheese(Long weight, Long calories, Float qualityMultiplier) {
        super("Cheese", weight, calories, qualityMultiplier);
    }
}
