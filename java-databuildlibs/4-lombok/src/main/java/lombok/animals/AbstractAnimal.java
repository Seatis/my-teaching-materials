package lombok.animals;

import com.google.common.collect.ImmutableList;
import com.google.common.collect.Lists;
import lombok.foods.Food;
import org.joda.time.LocalDate;

import java.util.List;

/**
 * Created by kicsen on 2016. 12. 12..
 */
public abstract class AbstractAnimal implements Animal {
    private String name;
    private LocalDate birthDate;
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
    public Integer getChildrenNumber() {
        return this.children.size();
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
    public String getName() {
        return name;
    }

    @Override
    public LocalDate getBirthDate() {
        return birthDate;
    }

    @Override
    public ImmutableList<? extends Animal> getChildren() {
        return ImmutableList.copyOf(children);
    }

    @Override
    public Long getMovedDistanceInMilliMeters() {
        return movedDistanceInMilliMeters;
    }

    @Override
    public Double getHappiness() {
        return happiness;
    }

    @Override
    public Long getWeightInGram() {
        return weightInGram;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof AbstractAnimal)) return false;

        AbstractAnimal that = (AbstractAnimal) o;

        if (!name.equals(that.name)) return false;
        if (!birthDate.equals(that.birthDate)) return false;
        if (!children.equals(that.children)) return false;
        if (!movedDistanceInMilliMeters.equals(that.movedDistanceInMilliMeters)) return false;
        if (!happiness.equals(that.happiness)) return false;
        return weightInGram.equals(that.weightInGram);

    }

    @Override
    public int hashCode() {
        int result = name.hashCode();
        result = 31 * result + birthDate.hashCode();
        result = 31 * result + children.hashCode();
        result = 31 * result + movedDistanceInMilliMeters.hashCode();
        result = 31 * result + happiness.hashCode();
        result = 31 * result + weightInGram.hashCode();
        return result;
    }

    @Override
    public String toString() {
        return "AbstractAnimal{" +
                "name='" + name + '\'' +
                ", birthDate=" + birthDate +
                ", children=" + children +
                ", movedDistanceInMilliMeters=" + movedDistanceInMilliMeters +
                ", happiness=" + happiness +
                ", weightInGram=" + weightInGram +
                '}';
    }
}
