package lombok.foods;

import org.joda.time.LocalDate;

/**
 * Created by kicsen on 2016. 12. 12..
 */
public class Barley extends AbstractHorseFood {
    public Barley(Long weight, Float qualityMultiplier, LocalDate expirationDate) {
        super("Barley", weight, weight * 5, qualityMultiplier, expirationDate);
    }
}
