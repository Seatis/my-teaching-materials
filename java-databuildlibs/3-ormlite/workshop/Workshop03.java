import com.j256.ormlite.dao.Dao;
import com.j256.ormlite.dao.DaoManager;
import com.j256.ormlite.jdbc.JdbcConnectionSource;
import com.j256.ormlite.support.ConnectionSource;
import com.j256.ormlite.table.TableUtils;

import java.sql.SQLException;

public class Workshop03 {
    public static void main(String[] args) throws SQLException {
        String databaseUrl = "jdbc:sqlite:accounts03.db";

        ConnectionSource connectionSource = new JdbcConnectionSource(databaseUrl);

        TableUtils.createTableIfNotExists(connectionSource, Account.class);
        TableUtils.createTableIfNotExists(connectionSource, Address.class);

        Dao<Account, String> accountDao =
                DaoManager.createDao(connectionSource, Account.class);


        Account account = accountDao.queryForId("Captain America");
        if(account == null) {
            Account newAccount = new Account("Captain America", "uejnsd632**234.", new Address("1061", "Andrássy út", "Hungary", "Budapest"));

            accountDao.create(newAccount);
        }

        account = accountDao.queryForId("Captain America");
        System.out.println("Account: " + account.toString());
    }
}
