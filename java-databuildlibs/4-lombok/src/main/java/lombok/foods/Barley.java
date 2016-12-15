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
public class Barley extends AbstractHorseFood {
    @Builder
    protected Barley(Long weight, Float qualityMultiplier, LocalDate expirationDate) {
        super("Barley", weight, weight * 5, qualityMultiplier, expirationDate);
    }
}
