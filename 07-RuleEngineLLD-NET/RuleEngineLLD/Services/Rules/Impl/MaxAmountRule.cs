using RuleEngineLLD.Models;
using RuleEngineLLD.Services.Rules;

namespace RuleEngineLLD.Services.Rules.Impl;

/// <summary>
/// Rule that checks if an expense amount exceeds a maximum limit.
/// Uses readonly field (like Java's final) to store the max amount.
/// </summary>
public class MaxAmountRule : IExpenseRule
{
    private readonly double _maxAmount;

    // Constructor - sets the readonly field
    public MaxAmountRule(double maxAmount)
    {
        _maxAmount = maxAmount;
    }

    /// <summary>
    /// Checks if expense amount exceeds max amount.
    /// Returns null if valid, or Violation if exceeds limit.
    /// </summary>
    public Violation? Check(Expense expense)
    {
        if (expense.AmountUsd > _maxAmount)
        {
            return Violation.Of($"Expense amount is greater than the max amount id:{expense.ExpenseId}");
        }

        return null; // No violation
    }
}

