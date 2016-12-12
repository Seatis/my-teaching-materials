package lombok.animals;

import lombok.foods.Food;

import java.util.logging.Logger;

/**
 * Created by kicsen on 2016. 12. 12..
 */
public class Mouse extends AbstractAnimal {
    private static final Logger LOGGER = Logger.getLogger(Mouse.class.getSimpleName());

    public Mouse(String name, long weightInGram, double happiness) {
        super(name, weightInGram, happiness);
    }

    public void feed(Food food) {
        super.feed(food);
    }

    @Override
    public void logOwnInfo() {
        LOGGER.info(this.toString());
    }

    @Override
    protected int getMoveHappinessDecrease() {
        return 3;
    }

    @Override
    public String toString() {
        return "Mouse{" + super.toString() + "}";
    }
}
