#version 330 core

in vec3 Position;
in vec3 Normal;
in vec3 Color;
in vec2 UV;

uniform vec3 LightDirection;
uniform float LightIntensity;




uniform sampler2D MoonTexture;

uniform vec2 MoonTranslationSpeed = vec2(0.008, 0.00);

out vec4 OutColor;

void main()
{
	vec3 N = normalize(Normal);

	// inverte a dire��o para calcular o Lambertiano
	vec3 L = -normalize(LightDirection);
	
	// Dot entre dois vetores unit�rios � equivalente ao cosseno entre esses vetores
	// Quanto maior o �ngulo entre os vetores, menor � o cosseno entre eles
	float Lambertian = dot(N, L);

	// O clamp vai manter o valor do Lambertiano entre 0 e 1
	// Se o valor for negativa isso quer dizer que estamos virados pro lado
	// oposto a dire��o da luz.
	Lambertian = clamp(Lambertian, 0.0, 1.0);

	float SpecularReflection = 0.0;
	if (Lambertian > 0.0)
	{
	    // Vetor V
		vec3 ViewDirection = -normalize(Position);

		// Vetor R
		vec3 ReflectionDirection = reflect(-L, N);

		// Termo especular: (R . V) ^ alpha
		SpecularReflection = pow(dot(ReflectionDirection, ViewDirection), 25.0);

		// Limita o valor da reflec��o especular a n�meros positivos
		SpecularReflection = max(0.0, SpecularReflection);
	}

	
	vec3 MoonColor = texture(MoonTexture, UV + 100.0).rgb ;
	//vec3 CloudsColor = texture(CloudsTexture, UV + Time * CloudsRotationSpeed).rgb;

	vec3 SurfaceColor = MoonColor * 1.5;

	// A reflec��o difusa vai ser o produto do lambertiano com a intensidade
	// da luz e a cor da textura.
	vec3 DiffuseReflection = Lambertian * LightIntensity * SurfaceColor + SpecularReflection ;
	//DiffuseReflection = vec3{ 0.0,1.0,0.0 }
	OutColor = vec4(DiffuseReflection, 1.0);
}