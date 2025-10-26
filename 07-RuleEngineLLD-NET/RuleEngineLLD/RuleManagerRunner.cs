using RuleEngineLLD.Models;
using RuleEngineLLD.Registry;
using RuleEngineLLD.Services;
using RuleEngineLLD.Services.Rules;

namespace RuleEngineLLD;

/// <summary>
/// Orchestrates rule evaluation and displays results.
/// Takes a rule engine via constructor (dependency injection pattern).
/// </summary>
public class RuleManagerRunner
{
    private readonly IRuleEngine _ruleEngine;

    public RuleManagerRunner(IRuleEngine ruleEngine)
    {
        _ruleEngine = ruleEngine;
    }

    /// <summary>
    /// Runs the rule engine on a list of expenses and prints violations.
    /// </summary>
    public void Run(List<Expense> expenses)
    {
        // Get all rule registries
        var expenseRulesRegistry = RuleRegistry.GetExpenseRulesRegistry();
        var allExpenseRulesRegistry = RuleRegistry.GetAllExpenseRulesRegistry();
        var tripRulesRegistry = RuleRegistry.GetAllTripRulesRegistry();

        // Evaluate expenses against rules
        List<Violation> violations = _ruleEngine.Evaluate(
            expenses,
            expenseRulesRegistry,
            allExpenseRulesRegistry,
            tripRulesRegistry
        );

        // Print violations
        foreach (var violation in violations)
        {
            Console.WriteLine(violation.Message);
        }
    }
}

