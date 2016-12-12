package lombok.animals;

import lombok.foods.HorseFood;

import java.util.logging.Logger;

/**
 * Created by kicsen on 2016. 12. 12..
 */
public class Horse extends AbstractAnimal {
    private static final Logger LOGGER = Logger.getLogger(Horse.class.getSimpleName());

    public Horse(String name, long weightInGram, double happiness) {
        super(name, weightInGram, happiness);
    }

    public void feed(HorseFood food) {
        super.feed(food);
    }

    @Override
    public void logOwnInfo() {
        LOGGER.info(this.toString());
    }

    @Override
    protected int getMoveHappinessDecrease() {
        return 1;
    }

    @Override
    public String toString() {
        return "Horse{" + super.toString() + "}";
    }
}
