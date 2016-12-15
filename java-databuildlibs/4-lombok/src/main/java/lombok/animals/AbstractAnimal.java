package lombok.animals;

import com.google.common.collect.ImmutableList;
import com.google.common.collect.Lists;
import lombok.*;
import lombok.foods.Food;
import org.joda.time.LocalDate;

import java.util.List;

/**
 * Created by kicsen on 2016. 12. 12..
 */
@Getter
@Setter
@EqualsAndHashCode
@ToString
public abstract class AbstractAnimal implements Animal {

    @Setter(AccessLevel.NONE)
    private String name;

    @Setter(AccessLevel.NONE)
    private LocalDate birthDate;

    @Setter(AccessLevel.NONE)
    protected List<? extends Animal> children = Lists.newArrayList();
    protected Long movedDistanceInMilliMeters = 0L;
    protected Double happiness;
    protected Long weightInGram;

    public AbstractAnimal(String name, long weightInGram, double happiness) {
        this.name = name;
        this.weightInGram = weightInGram;
        this.happiness = happiness;
        this.birthDate = new LocalDate();
    }

    @Override
    public void move(long distanceInMilliMeters) {
        this.movedDistanceInMilliMeters += distanceInMilliMeters;
        this.happiness -= getMoveHappinessDecrease();
        this.weightInGram -= distanceInMilliMeters;
    }

    protected void feed(Food food) {
        this.weightInGram += food.getCalories();
        this.happiness += food.getWeight() * food.getQualityMultiplier();
    }

    protected abstract int getMoveHappinessDecrease();

    @Override
    public ImmutableList<? extends Animal> getChildren() {
        return ImmutableList.copyOf(children);
    }

    @Override
    public Integer getChildrenNumber() {
        return this.children.size();
    }
}
