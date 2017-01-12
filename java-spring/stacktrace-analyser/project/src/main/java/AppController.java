import model.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import packages.UserRepo;

/**
 * Created by aze on 2017.01.12..
 */
@Controller
@RequestMapping("/app")
public class AppController {

    @Autowired
    UserRepo repo;

    @GetMapping("/")
    public String index(Model model) {
        model.addAttribute("new_user", new User());
        model.addAttribute("yolo", repo.findAll());
        return "index";
    }

    @PostMapping("/app")
    public String create() {
        repo.save(new User());
        return "redirect:/";
    }
}
