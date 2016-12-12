package lombok.foods;

import org.joda.time.LocalDate;

/**
 * Created by kicsen on 2016. 12. 12..
 */
public class LumpSugar extends AbstractHorseFood {
    public LumpSugar(Long weight, Float qualityMultiplier, LocalDate expirationDate) {
        super("LumpSugar", weight, weight * 13, qualityMultiplier, expirationDate);
    }
}
