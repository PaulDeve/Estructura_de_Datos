# =============================
# Análisis de tiempos.csv
# Comparación de estructuras de datos
# =============================

# Leer datos
datos <- read.csv("tiempos.csv")

# -----------------------------
# Prueba estadística t-test
# -----------------------------
lista <- subset(datos, Estructura == "Lista")
arbol <- subset(datos, Estructura == "Arbol")

# Convertir las métricas en vectores (inserción, búsqueda, etc.)
lista_vals <- unlist(lista[2:5])
arbol_vals <- unlist(arbol[2:5])

# Prueba t pareada
resultado <- t.test(lista_vals, arbol_vals, paired = TRUE)
print(resultado)

# Interpretación del resultado
if (resultado$p.value < 0.05) {
  cat("✅ Existe diferencia significativa entre Lista y Árbol.\n")
} else {
  cat("❌ No existe diferencia significativa entre Lista y Árbol.\n")
}

# -----------------------------
# Visualización con ggplot2
# -----------------------------
# Instalar paquetes si no están
if (!require(ggplot2)) install.packages("ggplot2", dependencies = TRUE)
if (!require(reshape2)) install.packages("reshape2", dependencies = TRUE)

library(ggplot2)
library(reshape2)

# Reorganizar datos a formato largo
datos_largos <- melt(datos, id.vars = "Estructura")

# Gráfico de barras agrupadas
ggplot(datos_largos, aes(x = variable, y = value, fill = Estructura)) +
  geom_bar(stat = "identity", position = "dodge") +
  labs(
    title = "Comparación de Tiempos por Operación y Estructura",
    subtitle = "Datos generados con N = 10,000 (aprox.)",
    x = "Operación",
    y = "Tiempo (segundos)"
  ) +
  theme_minimal() +
  theme(legend.position = "top")

# Leer los datos desde el archivo CSV
datos <- read.csv("tiempos.csv")

# Instalar y cargar paquetes si no están
if (!require(ggplot2)) install.packages("ggplot2", dependencies = TRUE)
if (!require(reshape2)) install.packages("reshape2", dependencies = TRUE)
library(ggplot2)
library(reshape2)

# Reorganizar a formato largo
datos_largos <- melt(datos, id.vars = "Estructura")

# Mostrar gráfico de barras
grafico <- ggplot(datos_largos, aes(x = variable, y = value, fill = Estructura)) +
  geom_bar(stat = "identity", position = "dodge") +
  labs(
    title = "Comparación de Tiempos por Operación y Estructura",
    subtitle = "Medido con N = 10000",
    x = "Operación",
    y = "Tiempo (segundos)"
  ) +
  theme_minimal() +
  theme(legend.position = "top", plot.title = element_text(size = 14, face = "bold"))

# Mostrarlo en RStudio
print(grafico)

# Guardar gráfico como imagen PNG (opcional)
ggsave("grafico_tiempos.png", plot = grafico, width = 10, height = 6)
