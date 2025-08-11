# Portafolio Personal - Desarrollador Web

Una página web moderna, minimalista y responsiva para mostrar tus servicios de desarrollo web y atraer clientes potenciales.

## 🚀 Características

- **Diseño Moderno**: Interfaz limpia y profesional con animaciones suaves
- **Totalmente Responsivo**: Se adapta perfectamente a todos los dispositivos
- **Navegación Suave**: Scroll automático a las secciones
- **Galería Interactiva**: Modal para mostrar proyectos del portafolio
- **Formulario de Contacto**: Funcional con validaciones avanzadas
- **Animaciones Avanzadas**: Efectos de scroll, partículas, contadores y más
- **Sección de Testimonios**: Slider automático con testimonios de clientes
- **Planes y Precios**: Tarjetas de precios interactivas
- **Proceso de Trabajo**: Visualización del flujo de trabajo
- **Estadísticas Animadas**: Contadores que se animan al hacer scroll
- **Sistema de Partículas**: Efectos visuales en el hero
- **Efectos Parallax**: Animaciones basadas en el scroll
- **SEO Optimizado**: Estructura semántica y meta tags
- **Sin Dependencias**: Solo HTML, CSS y JavaScript puro

## 📁 Estructura de Archivos

```
├── index.html          # Página principal
├── styles.css          # Estilos CSS
├── script.js           # Funcionalidad JavaScript
└── README.md           # Este archivo
```

## 🎨 Personalización

### 1. Información Personal

Edita el archivo `index.html` y cambia:

- **Nombre**: Busca "Tu Nombre" y reemplázalo
- **Email**: Cambia "tuemail@ejemplo.com"
- **Teléfono**: Actualiza "+1 234 567 890"
- **Ubicación**: Modifica "Tu Ciudad, País"
- **Redes Sociales**: Actualiza los enlaces en la sección de contacto

### 2. Colores y Estilo

En `styles.css`, modifica las variables CSS en `:root`:

```css
:root {
    --primary-color: #2563eb;      /* Color principal */
    --primary-hover: #1d4ed8;      /* Color hover */
    --secondary-color: #f8fafc;    /* Color de fondo secundario */
    --text-color: #1e293b;         /* Color de texto principal */
    --text-light: #64748b;         /* Color de texto secundario */
}
```

### 3. Proyectos del Portafolio

En `script.js`, edita el array `portfolioData`:

```javascript
const portfolioData = [
    {
        title: "Nombre del Proyecto",
        description: "Descripción detallada del proyecto...",
        image: "URL_de_la_imagen",
        technologies: ["HTML5", "CSS3", "JavaScript"]
    },
    // Agrega más proyectos aquí
];
```

### 4. Habilidades Técnicas

En `index.html`, modifica las barras de habilidades:

```html
<div class="skill-item">
    <span class="skill-name">Tu Habilidad</span>
    <div class="skill-bar">
        <div class="skill-progress" style="width: 85%"></div>
    </div>
</div>
```

### 5. Imágenes

Reemplaza las imágenes placeholder con tus propias imágenes:

- **Foto personal**: Cambia la URL en la sección "Sobre Mí"
- **Proyectos**: Actualiza las URLs en el portafolio
- **Logo**: Puedes agregar tu logo en el header

## 🛠️ Instalación y Uso

1. **Descarga los archivos** en tu computadora
2. **Personaliza** la información según tus necesidades
3. **Sube los archivos** a tu servidor web
4. **¡Listo!** Tu portafolio estará funcionando

### Servidor Local (Opcional)

Para probar localmente:

```bash
# Con Python 3
python -m http.server 8000

# Con Node.js (si tienes http-server instalado)
npx http-server

# Con PHP
php -S localhost:8000
```

Luego abre `http://localhost:8000` en tu navegador.

## 📱 Funcionalidades

### Navegación
- Menú fijo en la parte superior con efecto de transparencia
- Navegación suave entre secciones
- Menú hamburguesa en móviles con animaciones
- Indicador de sección activa en tiempo real

### Hero Section
- Fondo animado con partículas flotantes
- Contadores animados de estadísticas
- Efecto de escritura en el título
- Botones con efectos hover avanzados
- Stack de tecnologías con tooltips

### Servicios
- Tarjetas con efectos hover y precios
- Lista de características por servicio
- Animaciones de entrada escalonadas
- CTA personalizado

### Portafolio
- Galería de proyectos con hover effects
- Modal detallado al hacer clic
- Información de tecnologías utilizadas
- Imágenes con zoom suave y overlay

### Sobre Mí
- Badge de experiencia animado
- Barras de habilidades con porcentajes
- Características destacadas con íconos
- Botones de acción (CV y contacto)

### Testimonios
- Slider automático cada 5 segundos
- Navegación por puntos
- Estrellas de calificación
- Información del autor

### Proceso de Trabajo
- Pasos numerados con íconos
- Línea de conexión entre pasos
- Efectos hover en cada paso
- Animaciones de entrada

### Planes y Precios
- 3 planes con precios claros
- Plan destacado (más popular)
- Lista de características por plan
- Botones de acción

### Formulario de Contacto
- Validación de campos en tiempo real
- Notificaciones de éxito/error
- Campo de presupuesto
- Información de contacto detallada
- Enlaces a redes sociales
- Diseño responsivo
- Preparado para integración con backend

### Animaciones Avanzadas
- Efectos de fade-in al hacer scroll
- Sistema de partículas en el hero
- Contadores animados
- Efectos parallax
- Transiciones suaves en botones
- Efectos hover mejorados
- Animaciones de carga
- Efectos de texto (gradientes, sombras)

## 🎯 SEO y Rendimiento

### Optimizaciones Incluidas
- Meta tags completos
- Estructura HTML semántica
- Imágenes optimizadas
- CSS y JS minificados (recomendado para producción)
- Carga rápida sin dependencias externas

### Para Mejorar el SEO
1. Agrega meta descriptions únicas
2. Optimiza las imágenes (WebP recomendado)
3. Configura Google Analytics
4. Agrega un sitemap.xml
5. Configura Google Search Console

## 🔧 Personalización Avanzada

### Agregar Nuevas Secciones

1. Crea la estructura HTML en `index.html`
2. Agrega los estilos en `styles.css`
3. Incluye la funcionalidad en `script.js` si es necesaria

### Integrar con Backend

Para el formulario de contacto, reemplaza la función de envío en `script.js`:

```javascript
// Ejemplo con Fetch API
fetch('/api/contact', {
    method: 'POST',
    headers: {
        'Content-Type': 'application/json',
    },
    body: JSON.stringify({
        name: name,
        email: email,
        subject: subject,
        message: message
    })
})
.then(response => response.json())
.then(data => {
    showNotification('Mensaje enviado con éxito!', 'success');
})
.catch(error => {
    showNotification('Error al enviar el mensaje', 'error');
});
```

## 🌟 Consejos para el Éxito

1. **Contenido de Calidad**: Escribe descripciones atractivas de tus servicios
2. **Imágenes Profesionales**: Usa fotos de alta calidad de tus proyectos
3. **Llamadas a la Acción**: Incluye botones claros para contactar
4. **Testimonios**: Agrega testimonios de clientes satisfechos
5. **Blog**: Considera agregar una sección de blog para SEO
6. **Analytics**: Instala Google Analytics para medir el tráfico

## 📞 Soporte

Si necesitas ayuda para personalizar tu portafolio:

1. Revisa los comentarios en el código
2. Consulta la documentación de HTML, CSS y JavaScript
3. Usa las herramientas de desarrollador del navegador para debuggear

## 📄 Licencia

Este proyecto es de código abierto y puedes usarlo libremente para tu portafolio personal.

---

**¡Que tengas éxito con tu portafolio! 🚀** 