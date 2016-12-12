package lombok;

import com.google.common.collect.Lists;
import lombok.animals.Animal;
import lombok.animals.Horse;
import lombok.animals.Mouse;
import lombok.foods.*;
import org.joda.time.LocalDate;
import org.joda.time.format.DateTimeFormat;
import org.joda.time.format.DateTimeFormatter;

import java.util.List;
import java.util.Random;

/**
 * Created by kicsen on 2016. 12. 12..
 */
public class MainApp {
    public static final Random RANDOM = new Random();

    public static void main(String[] args) {
        List<Animal> animals = Lists.newArrayList();
        animals.add(new Horse("Paci", 100000, 2300));
        animals.add(new Horse("Saci", 98000, 1300));
        animals.add(new Horse("Laci", 110000, 3300));
        animals.add(new Mouse("CinCin", 50, 100));
        animals.add(new Mouse("Siccc", 70, 120));

        List<HorseFood> horseFoods = Lists.newArrayList();
        DateTimeFormatter dateTimeFormatter = DateTimeFormat.forPattern("yyyy-MM-dd");
        horseFoods.add(new Barley(2300L, 1.2F, LocalDate.parse("2017-12-12", dateTimeFormatter)));
        horseFoods.add(new Barley(1700L, 1.6F, LocalDate.parse("2017-11-23", dateTimeFormatter)));
        horseFoods.add(new Hay(1000L, 1.1F, LocalDate.parse("2018-08-25", dateTimeFormatter)));
        horseFoods.add(new LumpSugar(300L, 3F, LocalDate.parse("2017-09-25", dateTimeFormatter)));

        Cheese cheese = new Cheese(400L, 1200L, 4F);

        System.out.println("Food storage:");
        for (HorseFood horseFood : horseFoods) {
            System.out.println(horseFood.toString());
        }
        System.out.println(cheese.toString());

        System.out.println("Initial animal states:");
        for (Animal animal : animals) {
            animal.logOwnInfo();
        }

        System.out.println("Random feeding ...");
        for (int i = 0; i < 10; i++) {
            Animal animal = animals.get(RANDOM.nextInt(animals.size()));
            if (animal instanceof Horse) {
                ((Horse) animal).feed(horseFoods.get(RANDOM.nextInt(horseFoods.size())));
            } else if (animal instanceof Mouse) {
                Mouse mouse = (Mouse) animal;
                int feedingRandom = RANDOM.nextInt(10000);
                if (feedingRandom % 100 == 0) {
                    mouse.feed(cheese);
                } else {
                    mouse.feed(horseFoods.get(feedingRandom % horseFoods.size()));
                }
            }
        }

        System.out.println("Animal states after random feeding:");
        for (Animal animal : animals) {
            animal.logOwnInfo();
        }

        System.out.println("Random animal movements...");
        for (Animal animal : animals) {
            animal.move(RANDOM.nextInt(10000));
        }

        System.out.println("Animal states after random movements:");
        for (Animal animal : animals) {
            animal.logOwnInfo();
        }
    }
}
