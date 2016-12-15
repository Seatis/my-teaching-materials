package lombok.foods;

import lombok.Builder;
import lombok.EqualsAndHashCode;
import lombok.ToString;
import org.joda.time.LocalDate;

/**
 * Created by kicsen on 2016. 12. 12..
 */
@ToString(callSuper = true)
@EqualsAndHashCode(callSuper = true)
public class LumpSugar extends AbstractHorseFood {
    @Builder
    protected LumpSugar(Long weight, Float qualityMultiplier, LocalDate expirationDate) {
        super("LumpSugar", weight, weight * 13, qualityMultiplier, expirationDate);
    }
}
