using RuleEngineLLD.Models;
using RuleEngineLLD.Services.Rules;

namespace RuleEngineLLD.Services;

/// <summary>
/// Interface for the rule engine that evaluates expenses against rules.
/// Dictionary in C# is like Java's Map.
/// </summary>
public interface IRuleEngine
{
    /// <summary>
    /// Evaluates expenses against all registered rules.
    /// </summary>
    /// <param name="expenses">List of expenses to validate</param>
    /// <param name="expenseRulesRegistry">Rules specific to expense types</param>
    /// <param name="allExpenseRulesRegistry">Rules that apply to all expenses</param>
    /// <param name="tripRulesRegistry">Rules that apply to trips (multiple expenses)</param>
    /// <returns>List of violations found</returns>
    List<Violation> Evaluate(
        List<Expense> expenses,
        Dictionary<ExpenseType, List<IExpenseRule>> expenseRulesRegistry,
        List<IExpenseRule> allExpenseRulesRegistry,
        List<ITripRule> tripRulesRegistry
    );
}

