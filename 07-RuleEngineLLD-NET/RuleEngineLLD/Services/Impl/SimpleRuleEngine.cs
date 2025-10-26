using RuleEngineLLD.Models;
using RuleEngineLLD.Services.Rules;

namespace RuleEngineLLD.Services.Impl;

/// <summary>
/// Simple implementation of the rule engine.
/// Implements IRuleEngine interface.
/// </summary>
public class SimpleRuleEngine : IRuleEngine
{
    public List<Violation> Evaluate(
        List<Expense> expenses,
        Dictionary<ExpenseType, List<IExpenseRule>> expenseRulesRegistry,
        List<IExpenseRule> allExpenseRulesRegistry,
        List<ITripRule> tripRulesRegistry
    )
    {
        List<Violation> violationsResult = new List<Violation>();

        // 1. Check all expenses against expense-type-specific rules and global expense rules
        foreach (var expense in expenses)
        {
            // Get rules for this expense type (or empty list if none)
            var expenseTypeRules = expenseRulesRegistry.GetValueOrDefault(expense.ExpenseType, new List<IExpenseRule>());

            CheckExpenseAgainstRules(expense, expenseTypeRules, violationsResult);
            CheckExpenseAgainstRules(expense, allExpenseRulesRegistry, violationsResult);
        }

        // 2. Check all expenses against trip-level rules
        foreach (var rule in tripRulesRegistry)
        {
            var violation = rule.Check(expenses);
            if (violation != null)
            {
                violationsResult.Add(violation);
            }
        }

        return violationsResult;
    }

    /// <summary>
    /// Helper method to check an expense against a list of rules.
    /// </summary>
    private void CheckExpenseAgainstRules(Expense expense, List<IExpenseRule> rules, List<Violation> violationsResult)
    {
        foreach (var rule in rules)
        {
            var violation = rule.Check(expense);
            if (violation != null)
            {
                violationsResult.Add(violation);
            }
        }
    }
}

