package lombok.foods;

import org.joda.time.LocalDate;

/**
 * Created by kicsen on 2016. 12. 12..
 */
public abstract class AbstractHorseFood extends AbstractFood implements HorseFood {

    protected LocalDate expirationDate;

    public AbstractHorseFood(String name, Long weight, Long calories, Float qualityMultiplier, LocalDate expirationDate) {
        super(name, weight, calories, qualityMultiplier);
        this.expirationDate = expirationDate;
    }

    @Override
    public LocalDate getExpirationDate() {
        return expirationDate;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof AbstractHorseFood)) return false;
        if (!super.equals(o)) return false;

        AbstractHorseFood that = (AbstractHorseFood) o;

        return expirationDate != null ? expirationDate.equals(that.expirationDate) : that.expirationDate == null;

    }

    @Override
    public int hashCode() {
        int result = super.hashCode();
        result = 31 * result + (expirationDate != null ? expirationDate.hashCode() : 0);
        return result;
    }

    @Override
    public String toString() {
        return "AbstractHorseFood{" + super.toString() + " expirationDate=" + expirationDate + '}';
    }
}
