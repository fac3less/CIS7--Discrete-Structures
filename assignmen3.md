Part1:
if math is easy then the homework is done and if it is sunny then camping is fun

(S ^ C) -> ( M v C)


Part 2:
(¬B -> ¬A) -> (( ¬B -> A) -> B)
((A -> B) ^ ( B -> A)) -> A

| A | B | ¬A | ¬B | ¬B -> ¬A | ¬B -> A | ((¬B -> A) -> B
|---|---|--- |--- | -------- | ------- | ---------------
| T | T | F  | F  | T        | T       | T
| T | F | F  | T  | F        | T       | T
| F | T | T  | F  | T        | T       | F
| F | F | T  | T  | T        | T       | F
	                     	

Tautology - Neither

Part 3:

(p ∧ q) → r , p → (q → r) implication x 3

(p ∧ q)' v r , p' v (q' v r) associative

(p ∧ q)' v r , (p' v q') v r de morg

(p ∧ q)' v r , (p ∧ q)' v r
------------------------------------------------------------------------
(q ∨ r) → p, (q → p)∧(r → p) implication x 3

(q ∨ r)' v p, (q' v p)∧(r' v p) distribution

(q ∨ r)' v p, p v (q' ^ r') de morg

(q ∨ r)' v p, p v (q v r)'

Part 4:

∃x∀y∀z(City(x) ∧ Traveler (y) ∧ Lives(z,x)) → (Loves(y,x) ∧ ¬Loves(z,x))

There are cities that all travelers love and all the people who live there don't love it

“No traveler loves the city they live in.”

∀x∀y(City(x) ∧ traveler(y) ∧ lives(y,x)) -> ¬loves(y,x)
