using RuleEngineLLD.Models;
using RuleEngineLLD.Services;
using RuleEngineLLD.Services.Impl;

namespace RuleEngineLLD;

/// <summary>
/// Main entry point for the Rule Engine application.
/// In .NET, Program.cs is automatically the entry point (similar to Java's Main class).
/// </summary>
class Program
{
    static void Main(string[] args)
    {
        // Create a list of expenses to test
        List<Expense> expenses = new List<Expense>();

        expenses.Add(new Expense("1", "1", 10.0, ExpenseType.Restaurant));
        expenses.Add(new Expense("2", "1", 50.0, ExpenseType.Restaurant));
        expenses.Add(new Expense("3", "1", 100.0, ExpenseType.Restaurant));

        // Create rule engine and runner
        IRuleEngine ruleEngine = new SimpleRuleEngine();
        RuleManagerRunner ruleManagerRunner = new RuleManagerRunner(ruleEngine);

        // Run the rule engine
        ruleManagerRunner.Run(expenses);
    }
}
