-- Questão 4
--  Tabuada

SELECT '===== Questao 4 =====' AS titulo;

\prompt 'Digite o numero para a tabuada: ' num

\prompt 'Digite o limite da tabuada: ' limite


WITH RECURSIVE 
    tabuada(i) AS (
        SELECT 1
        UNION ALL
        SELECT i + 1 FROM tabuada WHERE i + 1 <= :'limite'::int
    )

SELECT 
    :'num'::int || ' x ' || i || ' = ' || (:'num'::int * i) AS resultado
FROM tabuada;