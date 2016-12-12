package lombok.foods;

import org.joda.time.LocalDate;

/**
 * Created by kicsen on 2016. 12. 12..
 */
public abstract class AbstractFood implements Food {

    private String name;
    private Long weight;
    private Long calories;
    private LocalDate creationDate;
    protected Float qualityMultiplier;

    public AbstractFood(String name, Long weight, Long calories, Float qualityMultiplier) {
        this.name = name;
        this.weight = weight;
        this.calories = calories;
        this.qualityMultiplier = qualityMultiplier;
        this.creationDate = new LocalDate();
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public Long getWeight() {
        return weight;
    }

    @Override
    public Long getCalories() {
        return calories;
    }

    @Override
    public Float getQualityMultiplier() {
        return qualityMultiplier;
    }

    @Override
    public LocalDate getCreationDate() {
        return creationDate;
    }

    @Override
    public void setQualityMultiplier(Float qualityMultiplier) {
        this.qualityMultiplier = qualityMultiplier;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof AbstractFood)) return false;

        AbstractFood that = (AbstractFood) o;

        if (!name.equals(that.name)) return false;
        if (!weight.equals(that.weight)) return false;
        if (!calories.equals(that.calories)) return false;
        if (!creationDate.equals(that.creationDate)) return false;
        return qualityMultiplier.equals(that.qualityMultiplier);

    }

    @Override
    public int hashCode() {
        int result = name.hashCode();
        result = 31 * result + weight.hashCode();
        result = 31 * result + calories.hashCode();
        result = 31 * result + creationDate.hashCode();
        result = 31 * result + qualityMultiplier.hashCode();
        return result;
    }

    @Override
    public String toString() {
        return "AbstractFood{" +
                "name='" + name + '\'' +
                ", weight=" + weight +
                ", calories=" + calories +
                ", creationDate=" + creationDate +
                ", qualityMultiplier=" + qualityMultiplier +
                '}';
    }
}
