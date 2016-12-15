package lombok.foods;

import lombok.Builder;
import lombok.EqualsAndHashCode;
import lombok.ToString;

/**
 * Created by kicsen on 2016. 12. 12..
 */
@ToString(callSuper = true)
@EqualsAndHashCode(callSuper = true)
public class Cheese extends AbstractFood {
    @Builder
    protected Cheese(Long weight, Long calories, Float qualityMultiplier) {
        super("Cheese", weight, calories, qualityMultiplier);
    }
}
