puts gets.scan(/[A-Z][a-z]*+[A-Z]/).sort_by(&:downcase).join
