package lombok.animals;

import lombok.Builder;
import lombok.EqualsAndHashCode;
import lombok.ToString;
import lombok.extern.java.Log;
import lombok.foods.HorseFood;

/**
 * Created by kicsen on 2016. 12. 12..
 */
@Log
@ToString(callSuper = true)
@EqualsAndHashCode(callSuper = true)
public class Horse extends AbstractAnimal {

    @Builder
    public Horse(String name, long weightInGram, double happiness) {
        super(name, weightInGram, happiness);
    }

    public void feed(HorseFood food) {
        super.feed(food);
    }

    @Override
    public void logOwnInfo() {
        log.info(this.toString());
    }

    @Override
    protected int getMoveHappinessDecrease() {
        return 1;
    }
}
