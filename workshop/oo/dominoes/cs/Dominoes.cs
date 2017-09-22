using System;
using System.Collections.Generic;

namespace Domino
{
    public class Dominoes
    {
        public static void Main(string[] args)
        {
            var dominoes = initializeDominoes();
            // You have the list of Dominoes
            // Order them into one snake where the adjacent dominoes have the same numbers on their adjacent sides
            // Create a function to write the dominous to the console in the following format
            // eg: [2, 4], [4, 3], [3, 5] ...

        }

        public static List<Domino> InitializeDominoes()
        {
            var dominoes = new List<Domino>();
            dominoes.add(new Domino(5, 2));
            dominoes.add(new Domino(4, 6));
            dominoes.add(new Domino(1, 5));
            dominoes.add(new Domino(6, 7));
            dominoes.add(new Domino(2, 4));
            dominoes.add(new Domino(7, 1));
            return dominoes;
        }
    }
}
