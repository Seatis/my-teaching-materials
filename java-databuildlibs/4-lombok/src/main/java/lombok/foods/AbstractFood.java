package lombok.foods;

import lombok.*;
import org.joda.time.LocalDate;

/**
 * Created by kicsen on 2016. 12. 12..
 */
@AllArgsConstructor(access = AccessLevel.PRIVATE)
@Getter
@ToString
@EqualsAndHashCode
public abstract class AbstractFood implements Food {

    private String name;
    private Long weight;
    private Long calories;
    private LocalDate creationDate;
    @Setter
    protected Float qualityMultiplier;

    public AbstractFood(String name, Long weight, Long calories, Float qualityMultiplier) {
        this(name, weight, calories, new LocalDate(), qualityMultiplier);
    }
}
