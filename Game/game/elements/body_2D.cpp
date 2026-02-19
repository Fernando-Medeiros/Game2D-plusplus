#include <body_2D.hpp>


Body2D::Body2D(Body2D& body) noexcept
	: disposed{ body.disposed },
	_node{ body.getNode().getPosition()}
{
}

Body2D::Body2D(const INode2D& linkedNode) noexcept
	: _node{ linkedNode.getPosition()},
	_movement{ *this }
{
}

[[nodiscard]] const INode2D& 
Body2D::getNode() const noexcept
{
	return _node;
}

//[[nodiscard]] const ETexture& 
//Body2D::getTexture() const noexcept
//{
//	return (ETexture)nullptr;
//}

//[[nodiscard]] const ILightComponent& 
//Body2D::getLightComponent() const noexcept
//{
//}
//
//[[nodiscard]] const IDamageComponent& 
//Body2D::getDamageComponent() const noexcept
//{
//}

[[nodiscard]] const IMovementComponent& 
Body2D::getMovementComponent() const noexcept
{
	return _movement;
}

//[[nodiscard]] const IStatisticComponent& 
//Body2D::getStatisticComponent() const noexcept
//{
//}

void Body2D::execute(IEventArgs* sender) noexcept
{}

void Body2D::setBody(IBody2D * entity) noexcept
{}

void Body2D::setNode(INode2D * node) noexcept
{}

void Body2D::setSprite(ETexture * sprite) noexcept
{}

void Body2D::translate(INode2D & linkedNode) noexcept
{}

bool Body2D::isDiposed() const noexcept
{
	return false;
}

void Body2D::dispose() noexcept
{}

