// Datos del portafolio para el modal
const portfolioData = [
    {
        title: "Tienda Online - Moda",
        description: "E-commerce completo desarrollado con React y Node.js. Incluye carrito de compras, pasarela de pagos, gestión de inventario y panel de administración.",
        image: "https://via.placeholder.com/400x300/2563eb/ffffff?text=Proyecto+1",
        technologies: ["React", "Node.js", "MongoDB", "Stripe"]
    },
    {
        title: "Página Corporativa",
        description: "Sitio web empresarial moderno con diseño responsivo. Optimizado para SEO y con integración de redes sociales.",
        image: "https://via.placeholder.com/400x300/7c3aed/ffffff?text=Proyecto+2",
        technologies: ["HTML5", "CSS3", "JavaScript", "PHP"]
    },
    {
        title: "Blog Personal",
        description: "Plataforma de contenido con CMS personalizado. Sistema de comentarios, categorías y búsqueda avanzada.",
        image: "https://via.placeholder.com/400x300/dc2626/ffffff?text=Proyecto+3",
        technologies: ["WordPress", "PHP", "MySQL", "jQuery"]
    },
    {
        title: "Landing Page",
        description: "Página de conversión optimizada para campañas de marketing. A/B testing integrado y análisis de métricas.",
        image: "https://via.placeholder.com/400x300/059669/ffffff?text=Proyecto+4",
        technologies: ["HTML5", "CSS3", "JavaScript", "Google Analytics"]
    },
    {
        title: "Aplicación Web",
        description: "Dashboard interactivo para gestión de proyectos. Gráficos en tiempo real y notificaciones push.",
        image: "https://via.placeholder.com/400x300/ea580c/ffffff?text=Proyecto+5",
        technologies: ["Vue.js", "Firebase", "Chart.js", "WebSockets"]
    },
    {
        title: "Portfolio Artístico",
        description: "Galería de trabajos creativos con filtros dinámicos y vista en lightbox. Diseño minimalista y elegante.",
        image: "https://via.placeholder.com/400x300/be185d/ffffff?text=Proyecto+6",
        technologies: ["HTML5", "CSS3", "JavaScript", "Lightbox"]
    }
];

// Variables globales
let currentModalIndex = 0;

// Función para manejar el cambio de tema
function initializeThemeToggle() {
    const themeToggle = document.getElementById('themeToggle');
    const icon = themeToggle.querySelector('i');
    
    // Verificar si hay un tema guardado en localStorage
    const savedTheme = localStorage.getItem('theme');
    if (savedTheme) {
        document.body.setAttribute('data-theme', savedTheme);
        updateThemeIcon(icon, savedTheme);
        updateHeaderTheme(savedTheme);
    } else {
        // Si no hay tema guardado, usar modo oscuro por defecto
        document.body.setAttribute('data-theme', 'dark');
        updateThemeIcon(icon, 'dark');
        updateHeaderTheme('dark');
        localStorage.setItem('theme', 'dark');
    }
    
    // Agregar evento de clic al botón
    themeToggle.addEventListener('click', function() {
        const currentTheme = document.body.getAttribute('data-theme');
        const newTheme = currentTheme === 'dark' ? 'light' : 'dark';
        
        // Cambiar tema
        document.body.setAttribute('data-theme', newTheme);
        
        // Actualizar icono
        updateThemeIcon(icon, newTheme);
        
        // Actualizar header
        updateHeaderTheme(newTheme);
        
        // Guardar preferencia en localStorage
        localStorage.setItem('theme', newTheme);
        
        // Mostrar notificación
        const themeText = newTheme === 'dark' ? 'Modo Oscuro' : 'Modo Claro';
        showNotification(`${themeText} activado`, 'success');
    });
}

// Función para actualizar el icono del tema
function updateThemeIcon(icon, theme) {
    if (theme === 'dark') {
        icon.className = 'fas fa-moon';
    } else {
        icon.className = 'fas fa-sun';
    }
}

// Función para actualizar el header según el tema
function updateHeaderTheme(theme) {
    const header = document.querySelector('.header');
    const scrollTop = window.pageYOffset;
    
    if (scrollTop > 100) {
        if (theme === 'dark') {
            header.style.background = 'rgba(15, 23, 42, 0.98)';
            header.style.boxShadow = '0 2px 10px rgba(0, 0, 0, 0.3)';
        } else {
            header.style.background = 'rgba(255, 255, 255, 0.98)';
            header.style.boxShadow = '0 2px 10px rgba(0, 0, 0, 0.1)';
        }
    } else {
        if (theme === 'dark') {
            header.style.background = 'rgba(15, 23, 42, 0.95)';
        } else {
            header.style.background = 'rgba(255, 255, 255, 0.95)';
        }
        header.style.boxShadow = 'none';
    }
}

// Inicialización cuando el DOM esté listo
document.addEventListener('DOMContentLoaded', function() {
    initializeThemeToggle();
    initializeNavigation();
    initializeScrollAnimations();
    initializeContactForm();
    initializeMobileMenu();
    initializeSkillBars();

    initializeCounterAnimation();
    initializeParticleSystem();
    initializeTypingEffect();
    initializeScrollReveal();
    initializeParallaxEffects();
});

// Navegación suave
function initializeNavigation() {
    const navLinks = document.querySelectorAll('.nav-link');
    
    navLinks.forEach(link => {
        link.addEventListener('click', function(e) {
            e.preventDefault();
            const targetId = this.getAttribute('href');
            const targetSection = document.querySelector(targetId);
            
            if (targetSection) {
                const headerHeight = document.querySelector('.header').offsetHeight;
                const targetPosition = targetSection.offsetTop - headerHeight;
                
                window.scrollTo({
                    top: targetPosition,
                    behavior: 'smooth'
                });
            }
        });
    });
}

// Función para scroll a sección específica
function scrollToSection(sectionId) {
    const section = document.getElementById(sectionId);
    if (section) {
        const headerHeight = document.querySelector('.header').offsetHeight;
        const targetPosition = section.offsetTop - headerHeight;
        
        window.scrollTo({
            top: targetPosition,
            behavior: 'smooth'
        });
    }
}

// Animaciones de scroll
function initializeScrollAnimations() {
    const observerOptions = {
        threshold: 0.1,
        rootMargin: '0px 0px -50px 0px'
    };

    const observer = new IntersectionObserver(function(entries) {
        entries.forEach(entry => {
            if (entry.isIntersecting) {
                entry.target.classList.add('visible');
            }
        });
    }, observerOptions);

    // Agregar clase fade-in a elementos que queremos animar
    const elementsToAnimate = document.querySelectorAll('.service-card, .portfolio-item, .about-content, .contact-content');
    elementsToAnimate.forEach(el => {
        el.classList.add('fade-in');
        observer.observe(el);
    });
}

// Menú móvil
function initializeMobileMenu() {
    const menuToggle = document.querySelector('.menu-toggle');
    const nav = document.querySelector('.nav');
    const navLinks = document.querySelectorAll('.nav-link');

    menuToggle.addEventListener('click', function() {
        nav.classList.toggle('active');
        menuToggle.classList.toggle('active');
    });

    // Cerrar menú al hacer clic en un enlace
    navLinks.forEach(link => {
        link.addEventListener('click', function() {
            nav.classList.remove('active');
            menuToggle.classList.remove('active');
        });
    });

    // Cerrar menú al hacer clic fuera
    document.addEventListener('click', function(e) {
        if (!nav.contains(e.target) && !menuToggle.contains(e.target)) {
            nav.classList.remove('active');
            menuToggle.classList.remove('active');
        }
    });
}

// Modal del portafolio
function openModal(index) {
    currentModalIndex = index;
    const modal = document.getElementById('portfolioModal');
    const modalImage = document.getElementById('modalImage');
    const modalTitle = document.getElementById('modalTitle');
    const modalDescription = document.getElementById('modalDescription');
    const modalTech = document.querySelector('.modal-tech');

    const project = portfolioData[index];
    
    modalImage.src = project.image;
    modalTitle.textContent = project.title;
    modalDescription.textContent = project.description;
    
    // Actualizar tecnologías
    modalTech.innerHTML = '';
    project.technologies.forEach(tech => {
        const techTag = document.createElement('span');
        techTag.className = 'tech-tag';
        techTag.textContent = tech;
        modalTech.appendChild(techTag);
    });

    modal.style.display = 'block';
    document.body.style.overflow = 'hidden';
}

function closeModal() {
    const modal = document.getElementById('portfolioModal');
    modal.style.display = 'none';
    document.body.style.overflow = 'auto';
}

// Cerrar modal con Escape
document.addEventListener('keydown', function(e) {
    if (e.key === 'Escape') {
        closeModal();
    }
});

// Cerrar modal haciendo clic fuera
document.getElementById('portfolioModal').addEventListener('click', function(e) {
    if (e.target === this) {
        closeModal();
    }
});

// Formulario de contacto
function initializeContactForm() {
    const form = document.getElementById('contactForm');
    
    form.addEventListener('submit', function(e) {
        e.preventDefault();
        
        // Obtener datos del formulario
        const formData = new FormData(form);
        const name = formData.get('name');
        const email = formData.get('email');
        const subject = formData.get('subject');
        const message = formData.get('message');
        
        // Validación básica
        if (!name || !email || !subject || !message) {
            showNotification('Por favor, completa todos los campos', 'error');
            return;
        }
        
        if (!isValidEmail(email)) {
            showNotification('Por favor, ingresa un email válido', 'error');
            return;
        }
        
        // Simular envío (aquí puedes integrar con tu backend)
        showNotification('Enviando mensaje...', 'info');
        
        setTimeout(() => {
            showNotification('¡Mensaje enviado con éxito! Te contactaré pronto.', 'success');
            form.reset();
        }, 2000);
    });
}

// Validación de email
function isValidEmail(email) {
    const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    return emailRegex.test(email);
}

// Sistema de notificaciones
function showNotification(message, type = 'info') {
    // Remover notificaciones existentes
    const existingNotifications = document.querySelectorAll('.notification');
    existingNotifications.forEach(notification => notification.remove());
    
    // Crear nueva notificación
    const notification = document.createElement('div');
    notification.className = `notification notification-${type}`;
    notification.innerHTML = `
        <div class="notification-content">
            <span class="notification-message">${message}</span>
            <button class="notification-close" onclick="this.parentElement.parentElement.remove()">&times;</button>
        </div>
    `;
    
    // Agregar estilos dinámicos
    notification.style.cssText = `
        position: fixed;
        top: 20px;
        right: 20px;
        background: ${type === 'success' ? '#10b981' : type === 'error' ? '#ef4444' : '#3b82f6'};
        color: white;
        padding: 1rem 1.5rem;
        border-radius: 8px;
        box-shadow: 0 4px 6px -1px rgba(0, 0, 0, 0.1);
        z-index: 3000;
        max-width: 400px;
        animation: slideInRight 0.3s ease;
    `;
    
    document.body.appendChild(notification);
    
    // Auto-remover después de 5 segundos
    setTimeout(() => {
        if (notification.parentElement) {
            notification.remove();
        }
    }, 5000);
}

// Animación de barras de habilidades
function initializeSkillBars() {
    const skillBars = document.querySelectorAll('.skill-progress');
    
    const observer = new IntersectionObserver(function(entries) {
        entries.forEach(entry => {
            if (entry.isIntersecting) {
                const progressBar = entry.target;
                const width = progressBar.style.width;
                progressBar.style.width = '0%';
                
                setTimeout(() => {
                    progressBar.style.width = width;
                }, 500);
                
                observer.unobserve(progressBar);
            }
        });
    }, { threshold: 0.5 });
    
    skillBars.forEach(bar => observer.observe(bar));
}

// Header con efecto de scroll
window.addEventListener('scroll', function() {
    const header = document.querySelector('.header');
    const scrollTop = window.pageYOffset;
    const currentTheme = document.body.getAttribute('data-theme');
    
    if (scrollTop > 100) {
        if (currentTheme === 'dark') {
            header.style.background = 'rgba(15, 23, 42, 0.98)';
            header.style.boxShadow = '0 2px 10px rgba(0, 0, 0, 0.3)';
        } else {
            header.style.background = 'rgba(255, 255, 255, 0.98)';
            header.style.boxShadow = '0 2px 10px rgba(0, 0, 0, 0.1)';
        }
        header.classList.add('scrolled');
    } else {
        if (currentTheme === 'dark') {
            header.style.background = 'rgba(15, 23, 42, 0.95)';
        } else {
            header.style.background = 'rgba(255, 255, 255, 0.95)';
        }
        header.style.boxShadow = 'none';
        header.classList.remove('scrolled');
    }
});

// Navegación activa según sección visible
window.addEventListener('scroll', function() {
    const sections = document.querySelectorAll('section[id]');
    const navLinks = document.querySelectorAll('.nav-link');
    const headerHeight = document.querySelector('.header').offsetHeight;
    
    let current = '';
    
    sections.forEach(section => {
        const sectionTop = section.offsetTop - headerHeight - 100;
        const sectionHeight = section.offsetHeight;
        
        if (window.pageYOffset >= sectionTop && window.pageYOffset < sectionTop + sectionHeight) {
            current = section.getAttribute('id');
        }
    });
    
    navLinks.forEach(link => {
        link.classList.remove('active');
        if (link.getAttribute('href') === `#${current}`) {
            link.classList.add('active');
        }
    });
});

// Efecto parallax suave en el hero
window.addEventListener('scroll', function() {
    const scrolled = window.pageYOffset;
    const hero = document.querySelector('.hero');
    const floatingCard = document.querySelector('.floating-card');
    
    if (hero && floatingCard) {
        const rate = scrolled * -0.5;
        floatingCard.style.transform = `translateY(${rate}px)`;
    }
});

// Lazy loading para imágenes (opcional)
function initializeLazyLoading() {
    const images = document.querySelectorAll('img[data-src]');
    
    const imageObserver = new IntersectionObserver(function(entries) {
        entries.forEach(entry => {
            if (entry.isIntersecting) {
                const img = entry.target;
                img.src = img.dataset.src;
                img.classList.remove('lazy');
                imageObserver.unobserve(img);
            }
        });
    });
    
    images.forEach(img => imageObserver.observe(img));
}

// Preloader (opcional)
window.addEventListener('load', function() {
    const preloader = document.querySelector('.preloader');
    if (preloader) {
        preloader.style.opacity = '0';
        setTimeout(() => {
            preloader.style.display = 'none';
        }, 300);
    }
});



// Animación de contadores
function initializeCounterAnimation() {
    const counters = document.querySelectorAll('.stat-number');
    
    const observer = new IntersectionObserver(function(entries) {
        entries.forEach(entry => {
            if (entry.isIntersecting) {
                const counter = entry.target;
                const target = parseInt(counter.getAttribute('data-target'));
                const duration = 2000; // 2 segundos
                const increment = target / (duration / 16); // 60fps
                let current = 0;
                
                const updateCounter = () => {
                    current += increment;
                    if (current < target) {
                        counter.textContent = Math.floor(current);
                        requestAnimationFrame(updateCounter);
                    } else {
                        counter.textContent = target;
                    }
                };
                
                updateCounter();
                observer.unobserve(counter);
            }
        });
    }, { threshold: 0.5 });
    
    counters.forEach(counter => observer.observe(counter));
}

// Sistema de partículas
function initializeParticleSystem() {
    const hero = document.querySelector('.hero');
    if (!hero) return;
    
    for (let i = 0; i < 50; i++) {
        createParticle(hero);
    }
}

function createParticle(container) {
    const particle = document.createElement('div');
    particle.className = 'particle';
    
    const size = Math.random() * 4 + 1;
    const x = Math.random() * 100;
    const y = Math.random() * 100;
    const duration = Math.random() * 3 + 2;
    const delay = Math.random() * 2;
    
    particle.style.cssText = `
        width: ${size}px;
        height: ${size}px;
        left: ${x}%;
        top: ${y}%;
        animation-duration: ${duration}s;
        animation-delay: ${delay}s;
    `;
    
    container.appendChild(particle);
    
    // Remover partícula después de la animación
    setTimeout(() => {
        if (particle.parentNode) {
            particle.remove();
            createParticle(container);
        }
    }, (duration + delay) * 1000);
}

// Efecto de escritura
function initializeTypingEffect() {
    const heroTitle = document.querySelector('.hero-title');
    if (!heroTitle) return;
    
    const text = heroTitle.textContent;
    heroTitle.textContent = '';
    
    let i = 0;
    const typeWriter = () => {
        if (i < text.length) {
            heroTitle.textContent += text.charAt(i);
            i++;
            setTimeout(typeWriter, 50);
        }
    };
    
    // Iniciar después de un pequeño delay
    setTimeout(typeWriter, 500);
}

// Efectos de scroll reveal
function initializeScrollReveal() {
    const elements = document.querySelectorAll('[data-aos]');
    
    const observer = new IntersectionObserver(function(entries) {
        entries.forEach(entry => {
            if (entry.isIntersecting) {
                const element = entry.target;
                const animation = element.getAttribute('data-aos');
                const delay = element.getAttribute('data-aos-delay') || 0;
                
                setTimeout(() => {
                    element.classList.add('animate-' + animation);
                }, delay);
                
                observer.unobserve(element);
            }
        });
    }, { threshold: 0.1 });
    
    elements.forEach(element => observer.observe(element));
}

// Efectos parallax
function initializeParallaxEffects() {
    window.addEventListener('scroll', function() {
        const scrolled = window.pageYOffset;
        const parallaxElements = document.querySelectorAll('.floating-shapes .shape');
        
        parallaxElements.forEach((element, index) => {
            const speed = 0.5 + (index * 0.1);
            const yPos = -(scrolled * speed);
            element.style.transform = `translateY(${yPos}px)`;
        });
    });
}

// Función para descargar CV
function downloadCV() {
    showNotification('Descargando CV...', 'info');
    // Aquí puedes agregar la lógica real para descargar el CV
    setTimeout(() => {
        showNotification('CV descargado exitosamente', 'success');
    }, 2000);
}

// Función para toggle FAQ
function toggleFAQ(element) {
    const faqItem = element.parentElement;
    const isActive = faqItem.classList.contains('active');
    
    // Cerrar todos los FAQ
    document.querySelectorAll('.faq-item').forEach(item => {
        item.classList.remove('active');
    });
    
    // Abrir el FAQ clickeado si no estaba activo
    if (!isActive) {
        faqItem.classList.add('active');
    }
}

// Efectos de hover mejorados
function initializeHoverEffects() {
    const cards = document.querySelectorAll('.service-card, .process-step');
    
    cards.forEach(card => {
        card.addEventListener('mouseenter', function() {
            this.style.transform = 'translateY(-10px) scale(1.02)';
        });
        
        card.addEventListener('mouseleave', function() {
            this.style.transform = 'translateY(0) scale(1)';
        });
    });
}

// Efectos de sonido (opcional)
function playHoverSound() {
    // Crear un audio context para efectos de sonido
    const audioContext = new (window.AudioContext || window.webkitAudioContext)();
    const oscillator = audioContext.createOscillator();
    const gainNode = audioContext.createGain();
    
    oscillator.connect(gainNode);
    gainNode.connect(audioContext.destination);
    
    oscillator.frequency.setValueAtTime(800, audioContext.currentTime);
    oscillator.frequency.exponentialRampToValueAtTime(600, audioContext.currentTime + 0.1);
    
    gainNode.gain.setValueAtTime(0.1, audioContext.currentTime);
    gainNode.gain.exponentialRampToValueAtTime(0.01, audioContext.currentTime + 0.1);
    
    oscillator.start(audioContext.currentTime);
    oscillator.stop(audioContext.currentTime + 0.1);
}

// Efectos de cursor personalizado
function initializeCustomCursor() {
    const cursor = document.createElement('div');
    cursor.className = 'custom-cursor';
    cursor.style.cssText = `
        position: fixed;
        width: 20px;
        height: 20px;
        background: var(--primary-color);
        border-radius: 50%;
        pointer-events: none;
        z-index: 9999;
        transition: transform 0.1s ease;
        mix-blend-mode: difference;
    `;
    document.body.appendChild(cursor);
    
    document.addEventListener('mousemove', function(e) {
        cursor.style.left = e.clientX - 10 + 'px';
        cursor.style.top = e.clientY - 10 + 'px';
    });
    
    // Efecto de hover en elementos interactivos
    const interactiveElements = document.querySelectorAll('a, button, .portfolio-item');
    interactiveElements.forEach(element => {
        element.addEventListener('mouseenter', () => {
            cursor.style.transform = 'scale(2)';
        });
        
        element.addEventListener('mouseleave', () => {
            cursor.style.transform = 'scale(1)';
        });
    });
}

// Efectos de carga de página
function initializePageLoader() {
    const loader = document.createElement('div');
    loader.className = 'page-loader';
    loader.innerHTML = `
        <div class="loader-content">
            <div class="loading-spinner"></div>
            <p>Cargando...</p>
        </div>
    `;
    loader.style.cssText = `
        position: fixed;
        top: 0;
        left: 0;
        width: 100%;
        height: 100%;
        background: white;
        display: flex;
        align-items: center;
        justify-content: center;
        z-index: 10000;
        transition: opacity 0.5s ease;
    `;
    
    document.body.appendChild(loader);
    
    window.addEventListener('load', function() {
        setTimeout(() => {
            loader.style.opacity = '0';
            setTimeout(() => {
                loader.remove();
            }, 500);
        }, 1000);
    });
}

// Efectos de scroll suave mejorado
function smoothScrollTo(element, duration = 1000) {
    const targetPosition = element.offsetTop - 100;
    const startPosition = window.pageYOffset;
    const distance = targetPosition - startPosition;
    let startTime = null;
    
    function animation(currentTime) {
        if (startTime === null) startTime = currentTime;
        const timeElapsed = currentTime - startTime;
        const run = ease(timeElapsed, startPosition, distance, duration);
        window.scrollTo(0, run);
        if (timeElapsed < duration) requestAnimationFrame(animation);
    }
    
    function ease(t, b, c, d) {
        t /= d / 2;
        if (t < 1) return c / 2 * t * t + b;
        t--;
        return -c / 2 * (t * (t - 2) - 1) + b;
    }
    
    requestAnimationFrame(animation);
}

// Inicializar efectos adicionales
document.addEventListener('DOMContentLoaded', function() {
    initializeHoverEffects();
    // initializeCustomCursor(); // Descomenta si quieres cursor personalizado
    initializePageLoader();
}); 