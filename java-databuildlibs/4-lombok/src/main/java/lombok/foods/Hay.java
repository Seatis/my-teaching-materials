package lombok.foods;

import org.joda.time.LocalDate;

/**
 * Created by kicsen on 2016. 12. 12..
 */
public class Hay extends AbstractHorseFood {
    public Hay(Long weight, Float qualityMultiplier, LocalDate expirationDate) {
        super("Hay", weight, weight * 2, qualityMultiplier, expirationDate);
    }
}
