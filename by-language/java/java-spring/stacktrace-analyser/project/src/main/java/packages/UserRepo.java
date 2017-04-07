package packages;

import model.User;
import org.springframework.data.repository.CrudRepository;

import java.util.List;

/**
 * Created by aze on 2017.01.12..
 */
public interface UserRepo extends CrudRepository {
    List<User> findAllById();
}
